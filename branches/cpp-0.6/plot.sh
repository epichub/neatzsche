#!/bin/sh
cat "templates/plot.plt.template" | sed -e "s!current.graph!${1}!g" -e "s!current.png!${1}.png!g" > "${1}.plt"
gnuplot "${1}.plt"
rm "${1}.plt"