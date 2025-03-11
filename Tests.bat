echo Running tests...

REM Тест 1: Ввод обычного числа 
SET MyProgram="%~1"
echo MyProgram
echo %MyProgram%
%MyProgram% < in1.txt > out1.txt 


REM Тест 2: Ввод неккоректного числа
%MyProgram% < in2.txt > out2.txt 

REM Тест 3: Ввод слишком большого числа 
%MyProgram% < in3.txt > out3.txt 

REM Тест 4: Ввод отрицательного числа 
%MyProgram% < in4.txt > out4.txt 

REM Тест 5: Ввод числа начинающего с 0
%MyProgram% < in5.txt > out5.txt 


echo All tests completed.