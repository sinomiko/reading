
PiSvrps.dll: dlldata.obj PiSvr_p.obj PiSvr_i.obj
	link /dll /out:PiSvrps.dll /def:PiSvrps.def /entry:DllMain dlldata.obj PiSvr_p.obj PiSvr_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del PiSvrps.dll
	@del PiSvrps.lib
	@del PiSvrps.exp
	@del dlldata.obj
	@del PiSvr_p.obj
	@del PiSvr_i.obj
