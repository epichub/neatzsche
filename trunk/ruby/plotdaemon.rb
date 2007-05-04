require 'plotter'

pid = fork do
  Signal.trap('HUP', 'IGNORE') # Don't die upon logout
  @plotter = Plotter.new
  sleep(10)
  @plotter.init("/home/www/www.generation.no/htdocs/gores","epic")
  @plotter.myloop(true)
end

Process.detach(pid)
