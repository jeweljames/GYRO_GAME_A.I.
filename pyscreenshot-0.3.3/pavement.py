from paver.easy import *
from paver.setuputils import setup

import paver.doctools
import paver.virtual
import paver.misctasks
from paved import *
from paved.dist import *
from paved.util import *
from paved.docs import *
from paved.pycheck import *
from paved.pkg import *

# get info from setup.py
setup_py = ''.join(
    [x for x in path('setup.py').lines() if 'distutils' not in x])
exec(setup_py)


options(
    sphinx=Bunch(
        docroot='docs',
        builddir='_build',
    ),
    #    pdf=Bunch(
    #        builddir='_build',
    #        builder='latex',
    #    ),
)

options.paved.clean.rmdirs += ['.tox',
                               'dist',
                               'build',
                               ]
options.paved.clean.patterns += ['*.pickle',
                                 '*.doctree',
                                 '*.gz',
                                 'nosetests.xml',
                                 'sloccount.sc',
                                 '*.pdf', '*.tex',
                                 '*.png',
                                 ]

options.paved.dist.manifest.include.remove('distribute_setup.py')
options.paved.dist.manifest.include.remove('paver-minilib.zip')
options.paved.dist.manifest.include.add('requirements.txt')


@task
@needs(
    #           'clean',
    'sloccount',
    'html',
    'pdf',
    'sdist',
    'nose', 'tox',
)
def alltest():
    'all tasks to check'
    pass


@task
@needs('manifest')
def sdist():
    """Overrides sdist to make sure that our MANIFEST.in is generated."""
    pass
