{
  "variables": {
    "module_name": "zfrog",
    "module_path": "./bin"
  },
  "targets": [
    {
      "target_name": "zfrog",
      "sources": [
        "src/njs_messages.cc",
        "src/njs_zfrog.cc",
        "src/zfrog_app.cc"
      ],
      "include_dirs" : [
          "<!(node -e \"require('nan')\")"
      ],
      "conditions": [
        ["OS==\"linux\" or OS==\"freebsd\" or OS==\"openbsd\" or OS==\"solaris\" or OS==\"aix\"", {
          "cflags_cc": [
            "-std=c++11",
            "-g",
            "-O0",
            "-I src",
            "-fPIC",
            "-Wno-format-contains-nul",
            "-Wno-deprecated-declarations"
          ]
        }]
      ]
    }, {
      "target_name": "action_after_build",
      "type": "none",
      "dependencies": [
        "<(module_name)"
      ],
      "copies": [
        {
          "files": [
            "<(PRODUCT_DIR)/<(module_name).node"
          ],
          "destination": "<(module_path)"
        }
      ]
    }
  ]
}
