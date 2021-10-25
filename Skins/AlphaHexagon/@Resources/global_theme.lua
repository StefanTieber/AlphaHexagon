function Initialize()
	ChangeSystem = SELF:GetOption('ChangeSystemTheme', '')
	CurrentTheme = SKIN:GetVariable('Theme', '')

	FilePath = SKIN:GetVariable('@') .. 'global_theme.inc'
	LightThemeString = '[Variables]\nTheme=light\n'
	DarkThemeString = '[Variables]\nTheme=dark\n'
end

function Switch()
	if CurrentTheme == 'light' then
		SetDarkTheme()
	else
		SetLightTheme()
	end
end

function SetLightTheme()
	WriteFile(FilePath, LightThemeString)
	if ChangeSystem == 'on' then
		os.execute('@reg add "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize" /t REG_DWORD /v "SystemUsesLightTheme" /d 1 /f')
	end
end

function SetDarkTheme()
	WriteFile(FilePath, DarkThemeString)
	if ChangeSystem == 'on' then
		os.execute('@reg add "HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize" /t REG_DWORD /v "SystemUsesLightTheme" /d 0 /f')
	end
end

function WriteFile(FilePath, Contents)
	local File = io.open(FilePath, 'w')

	if not File then
		print('WriteFile: unable to open file at ' .. FilePath)
		return
	end

	File:write(Contents)
	File:close()

	return true
end
