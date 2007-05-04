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
menu.runner
