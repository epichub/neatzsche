#!/bin/bash

# Convert from network created by Network::saveText to network as
# outputted by operator<<(std::ostream& os, Network &net).

read type
read num_input
read num_hidden
read num_output

echo "Reading network type $type with $num_input inputs, $num_hidden hidden nodes and $num_output ouputs." >&2
echo "EOF"
echo "Feed-Forward 1:"
echo $num_hidden

for (( h=1; $h <= $num_hidden; h++ )); do
    echo "basic_neuron $h:"
    echo "Unlesioned"
    read weights
    echo $weights
    echo ""
done

echo "EOF"
