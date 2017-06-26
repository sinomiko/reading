
ATLInternalsps.dll: dlldata.obj ATLInternals_p.obj ATLInternals_i.obj
	link /dll /out:ATLInternalsps.dll /def:ATLInternalsps.def /entry:DllMain dlldata.obj ATLInternals_p.obj ATLInternals_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del ATLInternalsps.dll
	@del ATLInternalsps.lib
	@del ATLInternalsps.exp
	@del dlldata.obj
	@del ATLInternals_p.obj
	@del ATLInternals_i.obj
