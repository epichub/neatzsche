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

def menu
  def readchoice
    @choice = gets
    case @choice
      when 1

      # system("./plot.sh")
      when 2
      when 3
      when 4
    end
  end
  def outputmenu
    puts "1.view plot"
    puts "2.view game"
    puts "3.play game"
    puts "4.view debuggame"
    print "choice: "
  end
  def runner
    outputmenu
    readchoice
    puts "your choice was " + @choice
    puts "cwd:" + FileUtils.getwd()
  end
end
# menu.runner
@neatrun = NEATRun.new
print "input number of hours: "
@hours = gets
@hours = @hours[0]
@hours = @hours-48
puts "you inputted: \"" + @hours.to_s + "\""
@neatrun.makelist(@hours)
@neatrun.selectfromlist()
