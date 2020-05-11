بسم الله الرحمن الرحيم
# simplust 
a simple Tokenstream written in C++.  
this is useful if you're going to create a  
programming language, it looks simple but powerful.  

# usage
clone or download this repository  
then run if you're using MinGW, msys2 or whatever c++ compiler.  
```
g++ -c Inst.cpp Tknst.cpp  
g++ -shared -o tokenstream.dll Inst.o Tknst.o  
g++ -o main.exe main.cpp tokenstream.dll  
main.exe  

```

no need to create dynamic link library  
you can just.  
```
g++ -o main.exe main.cpp Tknst.cpp Inst.cpp
```
or just copy the files where you execute 
your code i.e. visual studio, codeblocks, Clion...  

feel free to submit an issue or PR include your ideas or fix mistakes if found  
or even submit a future request. 