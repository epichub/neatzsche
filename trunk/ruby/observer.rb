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
require "plotter.rb"

def menu
  def init
    print "input number of hours: "
    @hours = gets
    @hours = @hours[0..(@hours.size-2)].to_i
    # @hours = @hours-48
    puts "you inputted: \"" + @hours.to_s + "\""
    @plotter = Plotter.new
    @plotter.init("/home/www/www.generation.no/htdocs/gores","epic",1)
  end
  def readchoice
    @choice = gets
    case @choice
    when 1
      @plotter.plotbam(true)
    when 2
    when 3
    when 4
    when 5
      exit
    end
  end
  def outputmenu
    puts "1.view plot(must have x forwarding..)"
    puts "2.view game"
    puts "3.play game"
    puts "4.view debuggame"
    puts "5. exit"
    print "choice: "
  end
  def runner
    outputmenu
    readchoice
    puts "your choice was " + @choice
    puts "cwd:" + FileUtils.getwd()
  end
end
menu.init
menu.runner

