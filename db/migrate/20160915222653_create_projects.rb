class CreateProjects < ActiveRecord::Migration
  def change
    create_table :projects do |t|
      t.string :path
      t.string :name
      t.integer :owner_id
      t.text :description

      t.timestamps null: false
    end
  end
end
