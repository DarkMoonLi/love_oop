@echo off

SET MyProgram="%~1"
if (%MyProgram% == "") (
	echo Please specify path to program
	exit /B 1
)

SET Out="output.txt"

%MyProgram% Empty.txt "Еcть ли тут что-нибудь?" > %Out% || goto err
fc EmptyOut.txt %Out% > nul || goto err
echo Test 1 passed

::%MyProgram% Input.txt "привет" > %Out% || goto err
::mistake with fc
::fc InputOut.txt %Out% > nul || goto err
::echo Test 2 passed

exit /B 0

:err
echo Test failed
exit /B 1