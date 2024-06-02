cmake_minimum_required(VERSION 3.24)
project(ID3v2.4MetaInfoParser)

set(CMAKE_CXX_STANDARD 17)

add_executable(ID3v2.4MetaInfoParser main.cpp id3v2.h id3v2.cpp frame.h frame.cpp COMM.h COMM.cpp COMR.h COMR.cpp ENCR.h ENCR.cpp EQU2.h EQU2.cpp ETCO.h ETCO.cpp GRID.h GRID.cpp LINK.h LINK.cpp OWNE.cpp OWNE.h PRIV.cpp PRIV.h PCNT.cpp PCNT.h POPM.cpp POPM.h POSS.cpp POSS.h RBUF.cpp RBUF.h RVA2.cpp RVA2.h SEEK.cpp SEEK.h SYLT.cpp SYLT.h textFrame.cpp textFrame.h TXXX.cpp TXXX.h UFID.cpp UFID.h USER.cpp USER.h USLT.cpp USLT.h urlFrame.cpp urlFrame.h WXXX.cpp WXXX.h encLenFrame.cpp encLenFrame.h)