const db = require('../database');

const actions = {
  getById: function(id, callback) {
    return db.query('select * from actions where id_actions=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from actions', callback);
  },
  add: function(actions, callback) {
    return db.query(
      'insert into actions (action_type,amount,date, account_id_account) values(?,?,?,?)',
      [actions.action_type, actions.amount, actions.date, actions.account_id_account],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from actions where id_actions=?', [id], callback);
  },
  upamount: function(id, actions, callback) {
    return db.query(
      'upamount actions set action_type=?,amount=?, date=?, account_id_account=? where id_actions=?',
      [actions.action_type, actions.amount, actions.date, actions.account_id_account, id],
      callback
    );
  }
};
module.exports = actions;