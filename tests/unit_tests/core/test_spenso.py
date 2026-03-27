from __future__ import division

from __future__ import absolute_import
import math
import os

from posix import environ
import time
import tempfile as tempfile
from functools import wraps
from collections import namedtuple
import tests.IOTests as IOTests
import aloha
import aloha.aloha_object as aloha_obj
import aloha.aloha_lib as aloha_lib
from aloha.aloha_lib import *
import aloha.create_aloha as create_aloha
import aloha.aloha_writers as aloha_writers
#import models.sm.object_library as object_library
import tests.unit_tests as unittest
import madgraph.various.misc as misc
from six.moves import range
from six.moves import zip
pjoin = os.path.join
try:
    from symbolica.community.spenso import TensorNetwork,Representation,TensorName,TensorLibrary,LibraryTensor,TensorStructure

except ImportError:
    symbolica = None

set_global = misc.set_global
PARALLEL_TEST_INPUT_DIR = os.path.join(os.path.dirname(__file__), 'input_files')

class UFOLorentz(object):
    """ simple UFO LORENTZ OBJECT """

    def __init__(self, name='',spins=[],structure='1'):
        """fake lorentz initialization"""
        self.name = name
        self.spins=spins
        self.structure = structure


def read_parallel_test_input(*parts):
    with open(os.path.join(PARALLEL_TEST_INPUT_DIR, *parts)) as stream:
        return stream.read()
class IOTest_Spenso(IOTests.IOTestManager):
   @IOTests.createIOTest()
   def testIO_FFV1_spenso(self):
      """ target: FFV1C1_1.cpp
      """

      FFV1 = UFOLorentz(name = 'FFV1',
                spins = [ 2, 2, 3 ],
                structure = 'Gamma(3,2,1)')

      builder = create_aloha.AbstractRoutineBuilder(FFV1)
      # builder.apply_conjugation()
      amp = builder.compute_routine(1, keep_abstract=True)

      routine = amp.write(output_dir=None, language='spenso')

      open(pjoin(self.IOpath,'FFV1C1_1.cpp'),'w').write(routine)
