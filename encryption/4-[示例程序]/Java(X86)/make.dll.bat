javac ViKeyJavaObj.java  -cp ./
mkdir ViKey
copy ViKeyJavaObj.class .\ViKey\
javah -classpath ./ ViKey.ViKeyJavaObj 
pause