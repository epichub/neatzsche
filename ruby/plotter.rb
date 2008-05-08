#   Copyright 2007 Bjørn Magnus Mathisen
#   This file is part of NEATzsche.

#   NEATzsche is free software; you can redistribute it and/or modify it
#   under the terms of the GNU General Public License as published by
#   the Free Software Foundation; either version 2 of the License, or
#   (at your option) any later version.

#   NEATzsche is distributed in the hope that it will be useful, but
#   WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
#   General Public License for more details.

#   You should have received a copy of the GNU General Public License
#   along with NEATzsche; if not, write to the Free Software Foundation,
#   Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

require "fileutils"
require "run"
require "rubygems"
gem "net-ssh"
gem "net-sftp"
require 'net/ssh'
require 'net/sftp'
require "cgi"
require "socket"


class GenerationSFTP
  def init(host,user, dir)
    @session = Net::SSH.start(host,user , {:paranoid => false})
    @dir = dir
    if( dir[dir.size-1] != '/')
      @dir << '/'
    end
    @sftp = @session.sftp.connect
  end
  def mkdir(ndir)
    already = alreadythere(ndir)
    if(!already)
      @sftp.mkdir(@dir + ndir, :permissions => 0755)
    end
  end
  def putfile(lfile,rfile)
    already = alreadythere(rfile)
    puts "lfile:"
    puts lfile
    if(!already)
      @sftp.upload!(lfile,@dir+rfile)
      @sftp.setstat(@dir + rfile, :permissions => 0755)
    end
  end
  def alreadythere(path)
    already = false
    puts "path:"
    puts @dir+path
    @sftp.dir.foreach(@dir) do |item|
      #puts item.name
      if( item.name == path )
        already = true;
      end
    end
    #@sftp.close_handle(handle)
    already
  end
end



class Plotter
  @neatrun = NEATRun.new
  @graphfile = "test"
  def init(host,dir,user,hours,menu)
    @host = host
    @dir = dir
    @user = user
    FileUtils.chdir("../cpp")
    @neatrun = NEATRun.new
    if menu==true
      @neatrun.selectfromlist(hours)
    else 
      @neatrun.getnewest(hours)
    end
    if @neatrun.size()==0
      puts "not starting plotter.."
      exit
    else
      puts "starting plotter.."
    end
    @newestrun = @neatrun.getrf()

    @file = ""
    @plotfile = @neatrun.graphfile() + ".png"
    @plotbestfile = @neatrun.graphfile() + "-best.pdf"
#     puts "plotfile: \"" + @plotfile + "\""
    @rdir = @dir + @neatrun.base()[7..@neatrun.base().size]
    @rplotfile = @plotfile[7..@plotfile.size]
    @graphfile = @neatrun.graphfile()
    @curgenomefile = @neatrun.curgenomefile()
    @settingsfile = @neatrun.settingsfile()
#     puts "graphfile: " + @graphfile
#     puts "genomefile: " + @curgenomefile
    @gsftp = GenerationSFTP.new
    @gsftp.init(@host,@user,@dir)
    @hostname = Socket.gethostname()
    if @hostname["compute"]
      @hostname = "clustis2"
    end
    @basebase = @hostname + @neatrun.base()[8..@neatrun.base().size]
    @gsftp.mkdir(@basebase)
    @gsftp.putfile(@settingsfile, @basebase + "/settings") #upload plot
  end
  def plotbam(persist)
    if File.exist?(@graphfile) && File.size(@graphfile) > 0
      if(persist)
        system("./plot.sh " + @graphfile + " 1") #update plot
      else
        system("./plot.sh " + @graphfile + " 0") #update plot
      end
    end
    return @graphfile
  end
  def plotbest
    if File.exist?(@graphfile) && File.size(@graphfile) > 0
      system("./plotbest.sh " + @graphfile) #update plot
    end
    return @graphfile
  end
  def show
      if File.exist?(@curgenomefile)
        system("./show 0 " + @curgenomefile + " 0 > tmpshow")
      end
  end
  def myloop(loop)
    begin
      if File.exist?(@graphfile) && File.size(@graphfile) > 0
        plotbam(false)
        @gsftp.putfile(@plotfile, @basebase + "/bam.png") #upload plot
        FileUtils.rm @plotfile #delete file 
      end
      if File.exist?(@graphfile) && File.size(@graphfile) > 0
        plotbest()
        @gsftp.putfile(@plotbestfile, @basebase + "/best.png") #upload plot
        FileUtils.rm @plotbestfile #delete file 
      end
      if File.exist?(@curgenomefile)
        system("./show 0 " + @curgenomefile + " 0 > tmpshow")
        @gsftp.putfile(@curgenomefile, @basebase + "/curegenome") #upload curgenome      
        @gsftp.putfile('tmpshow', @basebase + "/" + 'show') #upload show
        FileUtils.rm 'tmpshow' #delete filen
      end


      sleep(30)
      @neatrun.getrf().update()
    end until @neatrun.getrf().getended() || !loop
  end

  def mylog(msg)
    File.open('plotter.log', 'a') {|f| f.puts msg}
  end

  def cgioutput
#    cgi = CGI.new# ("html4")  # add HTML generation methods
#    CGI.a("http://www.example.com") { "Example" }
    print CGI::pretty("<HTML><BODY></BODY></HTML>")
  end

end
