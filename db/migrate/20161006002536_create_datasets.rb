class CreateDatasets < ActiveRecord::Migration
  def change
    create_table :datasets do |t|
      t.string :path
      t.string :name
      t.string :type
      t.text :description
      t.integer :team_id
      t.integer :owner_id

      t.timestamps null: false
    end
  end
end
