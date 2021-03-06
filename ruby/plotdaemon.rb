#   Copyright 2007 Bj�rn Magnus Mathisen
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
require 'plotter'

pid = fork do
  Signal.trap('HUP', 'IGNORE') # Don't die upon logout
  @plotter = Plotter.new
  sleep(10)
  @plotter.init("generation.no","/var/www/www.generation.no/htdocs/gores","epic",1,false)
  @plotter.myloop(true)
end

Process.detach(pid)
