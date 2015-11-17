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
          '../third_party/boost_1_59_0/boost',
        ],
        'library_dirs': [
            '../third_party/boost_1_59_0/stage/lib',
        ],
        'libraries': [
            '-lboost_system',
            '../third_party/boost_1_59_0/stage/lib/libboost_system.a',
        ]
        'link_settings': {
          '-lboost_system',
          'library_dirs': [
              '../third_party/boost_1_59_0/stage/lib',
          ],
          'libraries': [
              '-lboost_system',
              '../third_party/boost_1_59_0/stage/lib/libboost_system.abc',
          ]
        },
      },
    ]
}
