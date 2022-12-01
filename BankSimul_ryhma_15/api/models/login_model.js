const db = require('../database');


const login={
  checkpin: function(cardnumber, callback) {
      return db.query('SELECT pin FROM card WHERE cardnumber = ?',[cardnumber], callback); 
    }
};
          
module.exports = login;