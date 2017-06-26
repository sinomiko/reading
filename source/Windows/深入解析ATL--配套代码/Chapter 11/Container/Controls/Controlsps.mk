
Controlsps.dll: dlldata.obj Controls_p.obj Controls_i.obj
	link /dll /out:Controlsps.dll /def:Controlsps.def /entry:DllMain dlldata.obj Controls_p.obj Controls_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del Controlsps.dll
	@del Controlsps.lib
	@del Controlsps.exp
	@del dlldata.obj
	@del Controls_p.obj
	@del Controls_i.obj
