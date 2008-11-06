##
#	\namespace	init
#
#	\remarks	Initializes default 3dsMax Python modules
#	
#	\author		beta@blur.com
#	\author		Blur Studio
#	\date		09/12/08
#

import Py3dsMax
import glob
import os.path

# Load all the default max modules
for path in glob.glob( Py3dsMax.installPath + "/_max_*/" ):
	moduleName 		= os.path.normpath( path ).split( os.path.sep )[-1]
	module 			= __import__( moduleName )
	Py3dsMax.__dict__[ moduleName.lstrip( '_max_' ) ] 	= module
	module.init()
	