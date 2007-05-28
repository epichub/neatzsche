#!/bin/sh
if [[ $2 = 0 ]]
then
    cat "templates/plot.plt.template" | sed -e "s!current.graph!${1}!g" -e "s!current.png!${1}.png!g" > "${1}.plt"
    gnuplot "${1}.plt"
else
    cat "templates/plotpersist.plt.template" | sed -e "s!current.graph!${1}!g" > "${1}.plt"
    gnuplot "${1}.plt"
fi

rm "${1}.plt"