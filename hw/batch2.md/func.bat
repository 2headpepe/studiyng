chcp 65001
set /a n=0
set /a A=%1
set /a B=%A% %% 4
set /a C=%A% %% 100
set /a D=%A% %% 400
echo %A% && echo %B% && echo %C% && echo %D%
if D EQU %n% (goto leap) else (goto 1)

:1
if C EQU %n% (goto noleap) else (goto 2)

:2
if B EQU %n% (goto leap) else (goto noleap)

:leap
echo %1 is a leap year
goto break

:noleap
echo %1 is Not a leap year
goto break

:break
