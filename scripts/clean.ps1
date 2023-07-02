$PWD_PATH = Get-Location
Set-Location (Split-Path -Parent $MyInvocation.MyCommand.Definition)
Remove-Item ../bin/*.ilk
Remove-Item ../bin/*.pdb
Remove-Item ../source/*.obj
Remove-Item ../source/*.pdb
Set-Location $PWD_PATH