#/bin/sh
DIR=../drawing/network/
cp $1 $DIR
cd $DIR
echo `pwd`
./draw.sh $1
rm $1
convert $1.svg $1.jpg
#rm $1.svg
xview $1.jpg 2&>/dev/null
#rm $1.jpg