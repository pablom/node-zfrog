#!/usr/bin/env node

/*  pool-redis-promise */
/* express-validation */
/* card-info */
/*
var cluster = require('cluster');

if( cluster.isMaster ) {
    var numWorkers = require('os').cpus().length;

    console.log((new Date()) + ' EGW cluster [' + process.pid +  '] setting up ' + numWorkers + ' workers...');

    for(var i = 0; i < numWorkers; i++) {
        cluster.fork();
    }

    cluster.on('online', function(worker) {
        console.log('Worker ' + worker.process.pid + ' is online');
    });

    cluster.on('exit', function(worker, code, signal) {
        console.log('Worker ' + worker.process.pid + ' died with code: ' + code + ', and signal: ' + signal);
        console.log('Starting a new worker');
        cluster.fork();
    });
} 
else {
*/
    var egw = require('./lib/egw');


    var fs = require('fs'),
        bodyParser = require("body-parser"),
        //https = require('https'),
        https = require(`./bin/zfrog`),
        path = require('path'),
        app = require('express')();
    
    var ffi = require('ffi');
 
    var libm = ffi.Library('libm', {
        'ceil': [ 'double', [ 'double' ] ]
    });

    /* set form urlencoded parser */
    app.use(bodyParser.urlencoded({ extended: false }));
    /* set JSON body parser */
    app.use(bodyParser.json());

/*
    app.all('/*', function(req, res) 
    {
        res.send('process ' + process.pid + ' says hello!').end();}
    )
*/


    var server = https.createServer({
        key: fs.readFileSync('key.pem'),
        cert: fs.readFileSync('server.pem'),
        keyp: 'mmm'
        }, app).listen(8888, function() {
            console.log('e-Commerce [' + process.pid + '] gateway is listening on port 8888 to all incoming requests');
    });
 
/*
    let server = https.createServer((req, res) => {
        
        //const rr = http.request;
    
        //console.log(`req ${rr.url}`);
    
        // const ip = req.socket.remoteAddress;
        //  const port = req.socket.remotePort;
        //  res.end(`Your IP address is ${ip} and your source port is ${port}.`);
    
        //res.setHeader('Foo', 'bar');
        res.end('Hello World!');
    });
     
    server.listen(8888, () => {
        console.log('Example app listening on port 8080!')
    });
*/

    const now = new Date(),
        theNo = (now.toISOString().replace(/[-T:Z\.]/g, '').substr(0, 14)).toString();

    //app.use('/', require('./handlers/'));

    //app.use(require('express-status-monitor')());

    /**********************************************************/
    /*      serves POST payment request                       */
    /**********************************************************/ 
    app.post('/payment/:term_id', function(req, res) {

	    const ip = req.socket.remoteAddress;
  	    const port = req.socket.remotePort;
  	    console.log(`[${process.pid}] Client IP address is ${ip} and source port is ${port}.`);

        var term_id = req.params.term_id;
        console.log('Terminal: ' + term_id);

        console.log('Amount: ' + req.body.amount);
        console.log('Currency: ' + req.body.currency);

        res.json(req.body);

        //res.send('process ' + process.pid + ' payment!').end();
    });

//}

