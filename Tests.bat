echo Running tests...

REM ���� 1: ���� �������� ����� 
SET MyProgram="%~1"
echo MyProgram
echo %MyProgram%
%MyProgram% < in1.txt > out1.txt 


REM ���� 2: ���� ������������� �����
%MyProgram% < in2.txt > out2.txt 

REM ���� 3: ���� ������� �������� ����� 
%MyProgram% < in3.txt > out3.txt 

REM ���� 4: ���� �������������� ����� 
%MyProgram% < in4.txt > out4.txt 

REM ���� 5: ���� ����� ����������� � 0
%MyProgram% < in5.txt > out5.txt 


echo All tests completed.