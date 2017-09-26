var zfrogLib = require(`./bin/zfrog`),
    bodyParser = require("body-parser"),
    path = require('path'),
    exp_app = require('express')();

/* set form urlencoded parser */
exp_app.use(bodyParser.urlencoded({ extended: false }));
/* set JSON body parser */
exp_app.use(bodyParser.json());

var app = new zfrogLib.zFrog();
var worker_count = app.workers;

console.log(worker_count);
