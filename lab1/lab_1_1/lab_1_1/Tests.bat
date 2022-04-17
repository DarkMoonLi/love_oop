@echo off

SET MyProgram="%~1"
if (%MyProgram% == "") (
	echo Please specify path to program
	exit /B 1
)

SET Out="%TEMP%\outputTemp.txt"

:: ������ ����
%MyProgram% %TestOut%Empty.txt "�c�� �� ��� ���-������?" > %Out% || goto err
fc %TestOut%EmptyOut.txt %Out% > nul || goto err
echo Test 1 passed

:: ��������� ��������� ������
%MyProgram% Input.txt ������ > %Out% || goto err
fc MultipleOccurrencesOut.txt %Out% > nul || goto err
echo Test 2 passed

:: ���� ��������� ������
%MyProgram% Input.txt "����" > %Out% || goto err
fc OneOccurrenceOut.txt %Out% > nul || goto err
echo Test 3 passed

:: ��� ���������
%MyProgram% Input.txt "�����-������ ����������" > %Out% || goto err
fc ZeroOccurrencesOut.txt %Out% > nul || goto err
echo Test 4 passed

echo All tests were successful.
exit /B 0

:err
echo Test failed
exit 1