const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'root',
  password: '4712',
  database: 'banksimul15'
});
module.exports = connection;