var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const db = require('./database'); //const lisatty testiksi
const bcrypt = require('bcryptjs');
const basicAuth = require('express-basic-auth');

var customerRouter = require('./routes/customer');
var cardRouter = require('./routes/card');
var accountRouter = require('./routes/account');
var actionsRouter = require('./routes/actions');
var loginRouter = require('./routes/login');
var userRouter = require('./routes/user');


var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/customer', customerRouter);
app.use('/card', cardRouter);
app.use('/account', accountRouter);
app.use('/actions', actionsRouter);
app.use('/login', loginRouter);
app.use('/user', userRouter);


module.exports = app;
