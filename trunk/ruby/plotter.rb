require "fileutils"
require "run"
require "rubygems"
gem "net-ssh"
gem "net-sftp"
require 'net/ssh'
require 'net/sftp'
require "cgi"

class GenerationSFTP
  def init(user, dir)
    @session = Net::SSH.start( 'generation.no',user , {:paranoid => false})
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
    if(!already)
      @sftp.put_file(lfile,@dir+rfile)
      @sftp.setstat(@dir + rfile, :permissions => 0755)
    end
  end
  def alreadythere(path)
    already = false
    handle = @sftp.opendir(@dir)
    items = @sftp.readdir(handle)
    items.each do |item|
      if( item.filename == path )
        already = true;
      end
    end
    @sftp.close_handle(handle)
    already
  end
end



class Plotter
  @neatrun = NEATRun.new
  @graphfile = "test"
  def init(dir,user)
    @dir = dir
    @user = user
    FileUtils.chdir("../cpp")
    @neatrun = NEATRun.new
    @neatrun.getnewest()
    if @neatrun.size()==0
      puts "not starting plotter.."
      exit
    else
      puts "starting plotter.."
    end
    @newestrun = @neatrun.getrf()

    @file = ""
    @plotfile = @neatrun.graphfile() + ".png"
    puts "plotfile: \"" + @plotfile + "\""
    @rdir = @dir + @neatrun.base()[7..@neatrun.base().size]
    @rplotfile = @plotfile[7..@plotfile.size]
    @graphfile = @neatrun.graphfile()
    @curgenomefile = @neatrun.curgenomefile()
    @settingsfile = @neatrun.settingsfile()
    puts "graphfile: " + @graphfile
    puts "genomefile: " + @curgenomefile
    @gsftp = GenerationSFTP.new
    @gsftp.init(@user,@dir)
    @basebase = @neatrun.base()[8..@neatrun.base().size]
    @gsftp.mkdir(@basebase)
    @gsftp.putfile(@settingsfile, @basebase + "/" + @settingsfile[8..@settingsfile.size]) #upload plot
  end

  def myloop(loop)
    begin
      
      system("./plot.sh " + @graphfile) #update plot
      @gsftp.putfile(@plotfile, @basebase + "/" + @plotfile[8..@plotfile.size]) #upload plot
      FileUtils.rm @plotfile #delete file

      system("./show 0 " + @curgenomefile + " 0 > tmpshow")
      @gsftp.putfile(@curgenomefile, @basebase + "/" + @curgenomefile[8..@curgenomefile.size]) #upload curgenome      
      @gsftp.putfile('tmpshow', @basebase + "/" + 'show') #upload show
      FileUtils.rm 'tmpshow' #delete file

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
