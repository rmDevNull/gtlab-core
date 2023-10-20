# SPDX-FileCopyrightText: 2023 German Aerospace Center (DLR)
#
# SPDX-License-Identifier: MPL-2.0+

import sys
import os

# generate os-compatible path
def _generateImportPath(*path):
    joinedPath = path[0]
    for i in range(1, len(path)):
        subPath = path[i]
        if os.name == 'nt':
            joinedPath += '\\'
        else:
            joinedPath += '/'
        joinedPath += subPath
    return joinedPath

# add path to custom object_map
sys.path.append(_generateImportPath('..', '..', '..', 'testing_resources', 'misc'))

from objectmaphelper import *
# add custom object_map
from object_names import *

# generated by squish
gtMainWin_Processes_Calculators_GtProcessDock = {"name": "Processes/Calculators", "type": "GtProcessDock", "visible": 1, "window": gtMainWindow}
processes_Calculators_GtProcessView = {"container": gtMainWin_Processes_Calculators_GtProcessDock, "type": "GtProcessView", "unnamed": 1, "visible": 1}
gtMainWin_QMenu = {"type": "QMenu", "unnamed": 1, "visible": 1, "window": gtMainWindow}
add_QMenu = {"title": "Add...", "type": "QMenu", "unnamed": 1, "visible": 1, "window": gtMainWin_QMenu}
