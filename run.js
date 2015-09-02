var chokidar = require('chokidar')
var exec = require('child_process').exec
var process = require('child_process')
var fs = require('fs')
require('shelljs/global')

var file = fs.readFileSync('conf/ag.txt', 'utf-8')
var watcher = chokidar.watch('code', {ignored: /^\./, persistent: true})

var agree = null

if(file.indexOf('t') > -1){
  if(file.indexOf('r') > -1){
    if(file.indexOf('u') > -1){
      if(file.indexOf('e') > -1){
        agree = true
      }
    }
  }
}


if(agree == true){
  watcher
    .on('add', function(path) {
      console.log('File', path, 'has been added')
    })
    .on('change', function(path) {
      console.log('File', path, 'has been changed')
      if (exec(__dirname + '\\' + path).code !== 0) {
        echo('Opened');
      }
    })
    .on('unlink', function(path) {
      console.log('File', path, 'has been removed')
    })
    .on('error', function(error) {
      console.error('Error happened', error)
    })
} else {
  console.log("YOU DON'T HAVE ACCESS TO THIS")
  
}
