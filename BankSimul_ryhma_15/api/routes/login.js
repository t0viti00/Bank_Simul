const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');

router.post('/', 
  function(request, response) {
    if(request.body.cardnumber && request.body.pin){
      const cardnumber = request.body.cardnumber;
      const pin = request.body.pin;
      console.log(cardnumber);
        login.checkpin(cardnumber, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
              console.log(dbResult[0].pin);
              bcrypt.compare(pin,dbResult[0].pin, function(err,compareResult) {
                if(compareResult) {
                  console.log("succes");
                  response.send(true);
                }
                else {
                    console.log("wrong pin");
                    response.send(false);
                }			
              }
              );
            }
            else{
              console.log("user does not exists");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("cardnumber or pin missing");
      response.send(false);
    }
  }
);

module.exports=router;