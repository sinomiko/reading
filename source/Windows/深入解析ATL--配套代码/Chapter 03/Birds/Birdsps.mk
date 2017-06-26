
Birdsps.dll: dlldata.obj Birds_p.obj Birds_i.obj
	link /dll /out:Birdsps.dll /def:Birdsps.def /entry:DllMain dlldata.obj Birds_p.obj Birds_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del Birdsps.dll
	@del Birdsps.lib
	@del Birdsps.exp
	@del dlldata.obj
	@del Birds_p.obj
	@del Birds_i.obj
