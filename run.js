var chokidar = require('chokidar')
var exec = require('child_process').exec
var process = require('child_process')
require('shelljs/global')

var watcher = chokidar.watch('code', {ignored: /^\./, persistent: true})

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
