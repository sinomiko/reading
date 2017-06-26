
thisps.dll: dlldata.obj this_p.obj this_i.obj
	link /dll /out:thisps.dll /def:thisps.def /entry:DllMain dlldata.obj this_p.obj this_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del thisps.dll
	@del thisps.lib
	@del thisps.exp
	@del dlldata.obj
	@del this_p.obj
	@del this_i.obj
