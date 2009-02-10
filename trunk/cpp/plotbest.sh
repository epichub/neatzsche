#!/bin/sh
cat "templates/plotbest.plt.template" | sed -e "s!current.graph!${1}!g" -e "s!current.pdf!${1}-best.pdf!g" > "${1}.plt"
gnuplot "${1}.plt"
rm "${1}.plt"