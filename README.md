بسم الله الرحمن الرحيم
# simplust 
a simple Tokenstream written in C++

# usage
clone or download this repository  
then run if you're using MinGW, msys2 or whatever c++ compiler.  
```
g++ -c Inst.cpp Tknst.cpp  
g++ -shared -o tokenstream.dll Inst.o Tknst.o  
g++ -o main.exe main.cpp tokenstream.dll
main.exe  

```