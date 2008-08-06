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

class MySFTP
  def init(host,user,dir,todir)
    @session = Net::SSH.start(host,user , {:paranoid => false})
    @dir = dir
    @todir = todir
    @user = user
    @host = host
    if( dir[dir.size-1] != '/')
      @dir << '/'
    end
    if( todir[todir.size-1] != '/')
      @todir << '/'
    end
    @sftp = @session.sftp.connect
  end
  def findNewest(thisdir, searchstring, excludestring)
    @newest = 0
#     puts "reading dir: " + thisdir + " from " + @user + "@" + @host
#     puts searchstring.size
    @sftp.dir.foreach(thisdir) do |entry|
      if(searchstring.size == 0 || (entry.name.index(searchstring)!=nil && entry.name.index(excludestring)==nil))
        cfile = @sftp.file.open(thisdir+entry.name)
        if(@newest<cfile.stat.mtime)
          @newest = cfile.stat.mtime
          @ffile = entry
        end
        cfile.close
      end
    end
    return @ffile
  end
  def getNewest()
    newestdir = findNewest(@dir,"","")
#     puts "found newest dir..:" + @dir+newestdir.name
    newestfile = findNewest(@dir+newestdir.name+"/","genome","xml")
#     puts "downloading: " + @dir+newestdir.name+"/"+newestfile.name
    @sftp.download!(@dir+newestdir.name+"/"+newestfile.name,@todir+newestfile.name)
#     puts "wrote file " + @file.longname + "to " @file.shortname
#     puts @file.name
#     puts "wrote to the file:" + @todir + newestfile.name
    return @todir+newestfile.name
  end
end

@mysftp = MySFTP.new
@mysftp.init("octopro.idi.ntnu.no","epic","/Users/epic/Documents/git/neatzsche/cpp/results","/Users/epic/Desktop/")
@mysftp.getNewest
