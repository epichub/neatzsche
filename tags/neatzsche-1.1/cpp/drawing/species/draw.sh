#!/bin/sh
java -cp ../xalan.jar:xml-apis.jar:../serializer.jar:../xercesImpl.jar org.apache.xalan.xslt.Process -in $1.xml -xsl graphSpecies.xsl -out $1.svg
