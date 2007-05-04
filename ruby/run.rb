require "fileutils"
require "find"

class Runfile
  def init(filen)
    @file = filen
    update
  end
  def update
    rfile = File.new(@file, "r")
    @base = rfile.gets.strip
    @ended = (rfile.gets == "ended")
    @runinfo = rfile.gets.strip
  end
  def getruninfo
    @runinfo
  end
  def getended
    @ended
  end
  def getbase
    @base
  end
end

class NEATRun
  @ended = false
  @norun = true
  @runfile
  @list = Hash.new
  FileUtils.chdir("../cpp")
  def setpid(ipid)
    @correctpath = @pid + ".runinfo"
    @norun = false
  end
  def makelist(hours)
    if(hours==0)#set for a year
      hours = 24*365
    end
    starttime = Time.now - (3600 * hours)#no older than one hour
    Find.find(".") do |path|
      if path[".runinfo"]
        thistime = File.new(path).ctime
        if(thistime>starttime)
          puts 'adding file: ' + path
          tmpval = Runfile.new
          tmpval.init(path)
          @list[thistime] = tmpval
        else
          puts 'not adding file: ' + path
        end
      end
    end
  end
  def printlist
    counter = 0
    @list.each{ |key,value|
      counter = counter+1
      print counter
      print ". time: " + key.to_s
      print " info: " + value.getruninfo()
      print " ended: " + value.getended()
    }
  end
  def selectfromlist
    printlist
    print "your selection: "
    s = gets
    @runfile = @list.to_a()[s.to_i-1][1]
    update
  end
  def getnewest
    @list = Hash.new
    makelist(1)
    if @list.size == 0
      @norun = true
    else
      @norun = false
      @runfile = @list.sort[@list.size-1][1]
      update
    end
  end
  def getrf
    return @runfile
  end
  def update
    @base = @runfile.getbase()
    @graphfile = @base + '.graph'
    @curgenomefile = @base + '-cur.genome'
    puts "just create curgenome file.."
    puts @curgenomefile
    @settingsfile = @base + ".settings"
  end
  def graphfile
    @graphfile
  end
  def settingsfile
    @settingsfile
  end
  def curgenomefile
    puts "returning"
    puts @curgenomefile
    @curgenomefile
  end
  def size
    @list.size
  end
  def base
    @base
  end
end

# run.getnewest
# puts "newest runinfo: " + run.getrf().getruninfo()
# run.selectfromlist
# puts "selected runinfo: " + run.getrf().getruninfo()
