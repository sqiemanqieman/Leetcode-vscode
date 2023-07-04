$PWD_PATH = Get-Location
Set-Location (Split-Path -Parent $MyInvocation.MyCommand.Definition)

Remove-Item ../bin/*.ilk
Remove-Item ../bin/*.pdb
Remove-Item ../bin/*.obj

Remove-Item ../header/*.ilk
Remove-Item ../header/*.pdb
Remove-Item ../header/*.obj

Remove-Item ../source/*.ilk
Remove-Item ../source/*.pdb
Remove-Item ../source/*.obj
Set-Location $PWD_PATH