class CreateWorkflows < ActiveRecord::Migration
  def change
    create_table :workflows do |t|
      t.string :path
      t.string :name
      t.text :description
      t.integer :project_id
      t.integer :creator_id
      t.text :history

      t.timestamps null: false
    end
  end
end
