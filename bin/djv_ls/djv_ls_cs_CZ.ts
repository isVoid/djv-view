<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="cs_CZ">
<context>
    <name>djvLsApplication</name>
    <message>
        <location filename="djvLsApplication.cpp" line="122"/>
        <location filename="djvLsApplication.cpp" line="172"/>
        <source>Cannot open: &quot;%1&quot;</source>
        <translation>Nelze otevřít: &quot;%1&quot;</translation>
    </message>
    <message>
        <location filename="djvLsApplication.cpp" line="235"/>
        <source>%1 %2 %3 %4</source>
        <translation>%1 %2 %3 %4</translation>
    </message>
    <message>
        <location filename="djvLsApplication.cpp" line="237"/>
        <source>%1 %2 %3 %4 %5</source>
        <translation>%1 %2 %3 %4 %5</translation>
    </message>
    <message>
        <location filename="djvLsApplication.cpp" line="270"/>
        <source>%1 %2</source>
        <translation>%1 %2</translation>
    </message>
    <message>
        <location filename="djvLsApplication.cpp" line="300"/>
        <source>%1:</source>
        <translation>%1:</translation>
    </message>
</context>
<context>
    <name>djvLsContext</name>
    <message>
        <location filename="djvLsContext.cpp" line="143"/>
        <source>-x_info</source>
        <translation>-x_info</translation>
    </message>
    <message>
        <location filename="djvLsContext.cpp" line="144"/>
        <source>-xi</source>
        <translation>-xi</translation>
    </message>
    <message>
        <location filename="djvLsContext.cpp" line="149"/>
        <source>-file_path</source>
        <translation>-file_path</translation>
    </message>
    <message>
        <location filename="djvLsContext.cpp" line="150"/>
        <source>-fp</source>
        <translation>-fp</translation>
    </message>
    <message>
        <location filename="djvLsContext.cpp" line="155"/>
        <source>-seq</source>
        <translation>-seq</translation>
    </message>
    <message>
        <location filename="djvLsContext.cpp" line="156"/>
        <source>-q</source>
        <translation>-q</translation>
    </message>
    <message>
        <location filename="djvLsContext.cpp" line="161"/>
        <source>-recurse</source>
        <translation>-recurse</translation>
    </message>
    <message>
        <location filename="djvLsContext.cpp" line="162"/>
        <source>-r</source>
        <translation>-r</translation>
    </message>
    <message>
        <location filename="djvLsContext.cpp" line="167"/>
        <source>-hidden</source>
        <translation>-hidden</translation>
    </message>
    <message>
        <location filename="djvLsContext.cpp" line="172"/>
        <source>-columns</source>
        <translation>-columns</translation>
    </message>
    <message>
        <location filename="djvLsContext.cpp" line="173"/>
        <source>-c</source>
        <translation>-c</translation>
    </message>
    <message>
        <location filename="djvLsContext.cpp" line="181"/>
        <source>-sort</source>
        <translation>-sort</translation>
    </message>
    <message>
        <location filename="djvLsContext.cpp" line="182"/>
        <source>-s</source>
        <translation>-s</translation>
    </message>
    <message>
        <location filename="djvLsContext.cpp" line="187"/>
        <source>-reverse_sort</source>
        <translation>-reverse_sort</translation>
    </message>
    <message>
        <location filename="djvLsContext.cpp" line="188"/>
        <source>-rs</source>
        <translation>-rs</translation>
    </message>
    <message>
        <location filename="djvLsContext.cpp" line="193"/>
        <source>-x_sort_dirs</source>
        <translation>-x_sort_dirs</translation>
    </message>
    <message>
        <location filename="djvLsContext.cpp" line="194"/>
        <source>-xsd</source>
        <translation>-xsd</translation>
    </message>
    <message>
        <location filename="djvLsContext.cpp" line="217"/>
        <source>djv_ls

    The djv_ls application is a command line tool for listing directories with file sequences.

    Example output:

    el_cerrito_bart.1k.tiff   File 2.23MB darby rw Mon Jun 12 21:21:55 2006
    richmond_train.2k.tiff    File 8.86MB darby rw Mon Jun 12 21:21:58 2006
    fishpond.1-749.png       Seq 293.17MB darby rw Thu Aug 17 16:47:43 2006

    Key:

    (name)                        (type) (size) (user) (permissions) (time)

    File types:                   Permissions:

    File - Regular file           r - Readable
    Seq  - File sequence          w - Writable
    Dir  - Directory              x - Executable

Usage

    djv_ls [file|directory]... [option]...

    file      - One or more files or image sequences
    directory - One or more directories
    option    - Additional options (see below)

    If no files or directories are given then the current directory will be used.

Options

    -x_info, -xi
        Don&apos;t show information, only file names.
    -file_path, -fp
        Show file path names.
    -seq, -q (value)
        Set file sequencing. Options = %1. Default = %2.
    -recurse, -r
        Descend into sub-directories.
    -hidden
        Show hidden files.
    -columns, -c (value)
        Set the number of columns for formatting output. A value of zero disables formatting.

Sorting Options

    -sort, -s (value)
        Set the sorting. Options = %3. Default = %4.
    -reverse_sort, -rs
        Reverse the sorting order.
    -x_sort_dirs, -xsd
        Don&apos;t sort directories first.
%5
Examples

    List the current directory:

    &gt; djv_ls

    List specific directories:

    &gt; djv_ls ~/movies ~/pictures

    Sort by time with the most recent first:

    &gt; djv_ls -sort time -reverse_sort
</source>
        <oldsource>djv_ls

    The djv_ls application is a command line tool for listing directories with file sequences.

    Example output:

    el_cerrito_bart.1k.tiff   File 2.23MB darby rw Mon Jun 12 21:21:55 2006
    richmond_train.2k.tiff    File 8.86MB darby rw Mon Jun 12 21:21:58 2006
    fishpond.1-749.png       Seq 293.17MB darby rw Thu Aug 17 16:47:43 2006

    Key:

    (name)                        (type) (size) (user) (permissions) (time)

    File types:                   Permissions:

    File - Regular file           r - Readable
    Seq  - File sequence          w - Writable
    Dir  - Directory              x - Executable

Usage

    djv_ls [file|directory]... [option]...

    file      - One or more files or image sequences
    directory - One or more directories
    option    - Additional options (see below)

    If no files or directories are given then the current directory will be used.

Options

    -x_info, -xi
        Don&apos;t show information, only file names.
    -file_path, -fp
        Show file path names.
    -seq, -q (value)
        Set file sequencing. Options = %1. Default = %2.
    -recurse, -r
        Descend into sub-directories.
    -hidden
        Show hidden files.
    -columns, -c (value)
        Set the number of columns for formatting output. A value of zero disables formatting.

Sorting Options

    -sort, -s (value)
        Set the sorting. Options = %3. Default = %4.
    -reverse_sort, -rs
        Reverse the sorting order.
    -x_sort_dirs, -xsd
        Don&apos;t sort directories first.
%5
Examples

    List the current directory:
    &gt; djv_ls

    List specific directories:
    &gt; djv_ls ~/movies ~/pictures

    Sort by time with the most recent first:
    &gt; djv_ls -sort time -reverse_sort
</oldsource>
        <translation type="unfinished"></translation>
    </message>
</context>
</TS>
