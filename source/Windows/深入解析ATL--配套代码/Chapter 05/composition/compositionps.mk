
compositionps.dll: dlldata.obj composition_p.obj composition_i.obj
	link /dll /out:compositionps.dll /def:compositionps.def /entry:DllMain dlldata.obj composition_p.obj composition_i.obj kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib 

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL $<

clean:
	@del compositionps.dll
	@del compositionps.lib
	@del compositionps.exp
	@del dlldata.obj
	@del composition_p.obj
	@del composition_i.obj
