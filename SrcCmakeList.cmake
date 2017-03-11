# SrcCmakeList.cmake
#
#  Created on: 2016-02-23
#      Author: Abdallah Benkadja
#       Email: abdou9989@gmail.com

# ------------------------------------------------------------------
# ------------------------------ Sources ---------------------------
# ------------------------------------------------------------------

# ------------------------------- Definition des variables ---------
set (srcDirTests ./src/Tests/)
set (srcDirTools ./src/Tools/)
set (srcDir ./src/)


# ---------------------- Definition des fichiers relatifs a Tools---------

set(srcToolsH
${srcDirTools}Tools.h
)

set(srcToolsCPP 
${srcDirTools}Tools.cpp

)

# ---------------------- Definition des fichiers relatifs a la calibration---------

set(srcTestsH
${srcDirTests}Test.h
)

set(srcTestsCPP 
${srcDirTests}Test.cpp
)
#------------------------Definition des *.h et *.cpp constitutifs du projet 
set(srcSahaProgH
${srcToolsH}
${srcTestsH}
${srcDir}SahaProgCmakeConfig.h

)

set(srcSahaProgCPP
${srcToolsCPP}
${srcTestsCPP}
${srcDir}SahaProg.cpp
)

# ------------------------------- Fin de la definition des variables --------------

# ---------------------------------------------------------------------------------
# ------------------------------ Linkage des libs ---------------------------------
# ---------------------------------------------------------------------------------

SET(LIBS ${QT_LIBRARIES} ${Boost_LIBRARIES} ${dlib_LIBRARIES})

#QT4_WRAP_CPP(SahaProg_HEADERS_MOC ${srcSahaProgH} OPTIONS -DBOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
QT4_AUTOMOC(${srcSahaProgH})
add_executable (SahaProg ${SahaProg_HEADERS_MOC}  ${srcSahaProgCPP} ) 
target_link_libraries(SahaProg ${LIBS})

