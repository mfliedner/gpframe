class AddUserCredentials < ActiveRecord::Migration
  def change
    add_column :users, :password_digest, :string
    add_column :users, :session_token, :string
  end
end
