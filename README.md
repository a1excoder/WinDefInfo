# WinDefInfo
## Information about Windows Defender, Exclusions/Regedit...


### Add path/executable file via PowerShell
#### Run as administrative user
```ps1
Add-MpPreference -ExclusionPath "$Env:AppData\Roaming" # path
Add-MpPreference -ExclusionPath "C:\$env:USERPROFILE\Documents\attacker.exe" # executable
```



### Add path/executable file via Regedit
```cmd
:: Path in regedit
:: HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows Defender\Exclusions\Paths




```








```c
int main(void)
{
    return 0;
}
```
