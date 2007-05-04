#!/bin/sh
java -cp ../xalan.jar:xml-apis.jar:../serializer.jar:../xercesImpl.jar org.apache.xalan.xslt.Process -in $1 -xsl format.xsl -out $1-tmp.xml
java -cp ../xalan.jar:xml-apis.jar:../serializer.jar:../xercesImpl.jar org.apache.xalan.xslt.Process -in $1-tmp.xml -xsl draw.xsl -out $1.svg
rm $1-tmp.xml