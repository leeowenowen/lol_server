{
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
          '../third_party/boost_1_59_0',
        ],
        'library_dirs': [
            '../third_party/boost_1_59_0/stage/lib',
        ],
        'link_settings': {
          'library_dirs': [
              '../third_party/boost_1_59_0/stage/lib',
          ],
          'libraries': [
              '-lboost_system',
          ]
        },
      },
    ]
}
