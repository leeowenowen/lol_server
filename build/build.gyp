{
    'variables': {
      'boost_home':'/home/wangli/env/boost_1_59_0',
    },
    'includes':[
      'common.gypi',
    ],
    'targets': [
      {
        'target_name': 'main',
        'type':'executable',
        'sources': [
          '../src/main.cpp',
        ],
        'include_dirs': [
          '<(boost_home)',
        ],
        'library_dirs': [
            '<(boost_home)/stage/lib',
        ],
        'link_settings': {
          'library_dirs': [
              '<(boost_home)/stage/lib',
          ],
          'libraries': [
              '-lboost_system',
              '-lfcgi',
          ]
        },
      },
    ]
}
